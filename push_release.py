import sys
import argparse
from git import Repo

def main(*args):
    parser = argparse.ArgumentParser(add_help=False)
    stored_args = parser.parse_args()

    # Pass this if you wish to create a new branch and PR
    parser.add_argument('-r', '--release_name', dest='release_name', required=True)

    release_name = stored_args.release_name
    repo = Repo(search_parent_directories=True)
    current = repo.create_head(release_name)
    current.checkout()

    print("Adding changes..")
    repo.index.add("README.md")
    repo.index.add("pdftron_linux.go")
    repo.index.add("pdftron_windows.go")
    repo.index.add("pdftron_darwin_arm64.go")
    repo.index.add("pdftron_darwin_x86_64.go")
    repo.index.add("shared_libs/*")
    repo.index.add("samples/*")
    repo.index.add("go.mod")

    print("Committing changes..")
    repo.index.commit("Added updates for latest PDFTronGo lib update.")
    print("Pushing changes..")
    repo.git.push("origin", release_name)

    print("You will now need to open a pull request on Github for branch %s to continue the release." % release_name)

if __name__ == '__main__':
    sys.exit(main(*sys.argv))
