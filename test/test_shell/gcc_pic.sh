HELLO=`mktemp noah-hello.XXXXXX`
cat << EOF > $HELLO.c
#include <stdio.h>

int main(){
  printf("hello, world!");
}
EOF
BIN=`mktemp noah-hello.XXXXXX`
$NOAH /usr/bin/gcc -fPIC -pie $HELLO.c -o $BIN
test -s $BIN -a "`$NOAH $BIN`" = "hello, world!"
RET=$?
rm -f $HELLO $HELLO.c $BIN
exit $RET
