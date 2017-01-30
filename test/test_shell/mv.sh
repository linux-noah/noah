TEMP1=`mktemp noah-mv.XXXXXX`
TEMP2=`mktemp noah-mv.XXXXXX`
echo "hello world" > $TEMP1
$NOAH $TARGET $TEMP1 $TEMP2
test ! -f $TEMP1 -a -f $TEMP2 -a "`cat $TEMP2`" = "hello world"
RET=$?
rm -f $TEMP2
exit $RET
