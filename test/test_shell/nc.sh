#!/bin/bash

$NOAH $TARGET -l 8082 <<<"hello" & 
RECEIVE="`$NOAH $TARGET localhost 8082`"
test "hello" = "$RECEIVE" || exit 1
