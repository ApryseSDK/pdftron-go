pipeline {
    agent {
        docker {
            label 'linux_fleet'
            image 'linux_gowrappers:latest'
            registryUrl 'https://448036597521.dkr.ecr.us-east-1.amazonaws.com'
            registryCredentialsId 'ecr:us-east-1:Jenkins'
            alwaysPull true
        }
    }

    parameters {
        string(defaultValue: '', description: 'What name to give the created branch.', name: 'RELEASE_NAME')
        boolean(defaultValue: false, description: 'Set to true if you wish to push the build to git.', name: 'SHOULD_PUSH')
    }

    stages {
        stage('Build') {
            steps {
                s3ArtifactCopyInvoke('PDFNetWrappers Go/' + params.VERSION, 'PDFTronGoLinux.zip')
                s3ArtifactCopyInvoke('PDFNetWrappers Go Windows/' + params.VERSION, 'PDFTronGoWindows.zip')
                s3ArtifactCopyInvoke('PDFNetWrappers Go Mac/' + params.VERSION, 'PDFTronGoMac.zip')
                s3ArtifactCopyInvoke('PDFNetWrappers Mac Arm/' + params.VERSION, 'PDFTronGoMacArm.zip')

                unzip zipFile: 'PDFTronGoLinux.zip'
                unzip zipFile: 'PDFTronGoWindows.zip'
                unzip zipFile: 'PDFTronGoMac.zip'
                unzip zipFile: 'PDFTronGoMacArm.zip'

                zip zipFile: 'PDFTronGo.zip'

                s3ArtifactUpload('PDFTronGo.zip')
            }
        }

        stage('Push') {
            when {
                expression {
                    return params.SHOULD_PUSH
                }
            }
            steps {
                sh """
                    python3 push-release.py --release-name=${params.RELEASE_NAME}
                """
            }
        }
    }

    post {
        failure {
            sendMail([
                currentBuild: currentBuild,
                env: env
            ])
        }
    }
}
