#! /bin/bash

VERSION=$1

# commit & push

VERNUMS=(${VERSION//./ })
VERSION_MAJOR=${VERNUMS[0]}
VERSION_MINOR=${VERNUMS[1]}
VERSION_PATCH=${VERNUMS[2]}

echo major version: $VERSION_MAJOR
echo minor version: $VERSION_MINOR
echo patch version: $VERSION_PATCH

FILE=`pwd`/`git rev-parse --show-cdup`/include/noah.h
sed -i "" "s/\\(define NOAH_MAJOR_VERSION\\).*/\\1 \"$VERSION_MAJOR\"/" $FILE
sed -i "" "s/\\(define NOAH_MINOR_VERSION\\).*/\\1 \"$VERSION_MINOR\"/" $FILE
sed -i "" "s/\\(define NOAH_PATCH_VERSION\\).*/\\1 \"$VERSION_PATCH\"/" $FILE

git add $FILE

while true; do
    read -p "commit and push? (type 'd' to show the changes) [y/n/d]" answer
    case $answer in
        "y") break;;
        "n") exit 1;;
        "d") git diff --cached
    esac
done

git commit -m "version $VERSION"
git push origin master

git tag $VERSION
git push origin --tags

echo successfully pushed noah $VERSION

# publish homebrew

URL=https://github.com/linux-noah/noah/archive/$VERSION.tar.gz

echo url: $URL

curl -LO $URL
SHA256=`shasum -a 256 $VERSION.tar.gz | cut -d ' ' -f 1`
rm $VERSION.tar.gz

echo sha256: $SHA256

if [[ -d homebrew-noah ]]; then
    cd homebrew-noah
    git reset --hard
    git pull
else
    git clone git@github.com:linux-noah/homebrew-noah.git
    cd homebrew-noah
fi

sed -i "" -e "8 s@.*@  url \"$URL\"@g" noah.rb
sed -i "" -e "9 s@.*@  version \"$VERSION\"@g" noah.rb
sed -i "" -e "10 s@.*@  sha256 \"$SHA256\"@g" noah.rb

git add noah.rb
git commit -m "version $VERSION"
git push origin master

cd ..
rm -rf homebrew-noah

echo successfully published noah $VERSION

while true; do
    read -p "upgrade noah on your system? [y/n]" answer
    case $answer in
        "y") break;;
        "n") exit 0;;
    esac
done

brew update
brew upgrade noah

echo successfully upgraded noah on your system
