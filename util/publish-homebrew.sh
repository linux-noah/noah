#! /bin/bash

VERSION=$1

while [[ -z $VERSION ]]; do
    read -p "select a version (type 'l' to show all versions): " VERSION
    if [[ $VERSION = l ]]; then
        git tag -l
    else
        break
    fi
done

echo installing $VERSION

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
