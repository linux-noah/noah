HELLO=`mktemp noah-hello.XXXXXX`
echo $HELLO.c >&2
cat << EOF > $HELLO.c
#include <stdio.h>

int main(){
  printf("hello, world!");
}
EOF
BIN=`mktemp noah-hello.XXXXXX`
echo $BIN >&2
$NOAH /usr/bin/gcc $HELLO.c -o $BIN
test -s $BIN -a "`$NOAH $BIN`" = "hello, world!"
RET=$?
rm -f $HELLO $HELLO.c $BIN
exit $RET
