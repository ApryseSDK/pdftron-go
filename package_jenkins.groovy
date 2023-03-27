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
        string(defaultValue: '', description: 'What version to pull from for packaging.', name: 'VERSION')
        string(defaultValue: '', description: 'What name to give the created branch.', name: 'RELEASE_NAME')
        booleanParam(defaultValue: false, description: 'Set to true if you wish to push the build to git.', name: 'SHOULD_PUSH')
    }

    stages {
        stage('Build') {
            steps {
                s3ArtifactCopyInvoke('PDFNetWrappers Go/' + params.VERSION.replace("/", "%2F"), 'PDFTronGoLinux.zip')
                s3ArtifactCopyInvoke('PDFNetWrappers Go Windows/' + params.VERSION.replace("/", "%2F"), 'PDFTronGoWin.zip')
                s3ArtifactCopyInvoke('PDNetWrappers Go Mac/' + params.VERSION.replace("/", "%2F"), 'PDFTronGoMac.zip')
                s3ArtifactCopyInvoke('PDFNetWrappers Mac Arm/' + params.VERSION.replace("/", "%2F"), 'PDFTronGoMacArm.zip')

                unzip zipFile: 'PDFTronGoLinux.zip'
                unzip zipFile: 'PDFTronGoWin.zip'
                unzip zipFile: 'PDFTronGoMac.zip'
                unzip zipFile: 'PDFTronGoMacArm.zip'
                sh 'rm -rf PDFTronGo*.zip'

                zip zipFile: 'PDFTronGo.zip', overwrite: true

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
                sshagent(['jenkins/xodo-shared-ssh-key']) {
                    sh """
                    git checkout -b ${params.RELEASE_NAME}
                    git add README.md
                    git add pdftron_linux.go
                    git add pdftron_windows.go
                    git add pdftron_darwin_arm64.go
                    git add pdftron_darwin_x86_64.go
                    git add shared_libs/mac/Lib/arm64/libPDFNetC.dylib
                    git add shared_libs/mac/Lib/arm64/libpdftron.dylib
                    git add shared_libs/mac/Lib/x86_64/libPDFNetC.dylib
                    git add shared_libs/mac/Lib/x86_64/libpdftron.dylib
                    git add shared_libs/unix/Lib/libPDFNetC.so
                    git add shared_libs/unix/Lib/libpdftron.so
                    git add shared_libs/win/Lib/pdftron.dll
                    git add shared_libs/win/Lib/PDFNetC.dll
                    git add samples/*
                    git add go.mod

                    git commit -m "Update for ${params.VERSION} release."
                    git push origin ${params.RELEASE_NAME}
                """
                }
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
