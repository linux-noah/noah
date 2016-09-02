HELLO=`mktemp /tmp/noah-hello.XXXXXX`.c
cat << EOF > $HELLO
#include <stdio.h>

int main(){
  printf("hello, world!");
}
EOF
BIN=`mktemp /tmp/noah-hello.XXXXXX`
$NOAH $TARGET $HELLO -o $BIN
test -s $BIN -a "`$NOAH $BIN`" = "hello, world!" || exit 1

