DIFF=$(diff $1 $2)
  if [ "$DIFF" != "" ]
  then
    echo $1 $2
    exit -1
  fi
