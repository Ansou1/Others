#!/bin/sh

FILE_NAME="./sh.db";

DISPLAY=0;
ACTION=0;
KEY="";
VALUE="";
NB_PARAM_OLD=$#;
NB_PARAM=0;
F_ENABLED=0;
K_ENABLED=0;

function usage()
{
    echo "Syntax error : Usage bdsh.sh [-k] [-f <db_file>] (put (<clef> | $<clef>) (<valeur> | $<clef>) | del (<clef> | $<clef>) [<valeur> | $<clef>] | select [<expr> | $<clef>] | flush )";
    exit;
}

while [ "$1" != "" ]; do
    case $1 in
	-f) #OPTION CHOIX DB
	    NB_PARAM=$(($NB_PARAM+1));
	    if [ $F_ENABLED == 1 ]; then
		usage;
	    fi
	    shift;
	    NB_PARAM=$(($NB_PARAM+1));
	    FILE_NAME=$1;
	    F_ENABLED=1;
	    ;;

	-k) #OPTION AFFICHAGE
	    DISPLAY=1;
	    if [ $K_ENABLED == 1 ]; then
		usage;
	    fi
	    K_ENABLED=1;
	    NB_PARAM=$(($NB_PARAM+1));
	    ;;

	put) #ACTION AJOUT
	    NB_PARAM=$(($NB_PARAM+1));
	    ACTION=1;
	    shift;
	    NB_PARAM=$(($NB_PARAM+1));
	    if [ "$1" == "" ] && [ $# == 0 ]; then
		usage;
	    fi
	    KEY=$1;
	    shift;
	    NB_PARAM=$(($NB_PARAM+1));
	    if [ "$1" == "" ] && [ $# == 0 ]; then
		usage;
	    fi
	    VALUE=$1;
	    ;;

	del) #ACTION DEL
	    NB_PARAM=$(($NB_PARAM+1));
	    ACTION=2;
	    shift;
	    NB_PARAM=$(($NB_PARAM+1));
	    if [ "$1" == "" ]; then
		usage;
	    fi
	    KEY=$1;
	    VALUE="²";
	    shift;
	    NB_PARAM=$(($NB_PARAM+1));
	    if [ "$1" != "" ] || [ $# == 1 ]; then
		VALUE=$1;
	    fi
	    ;;

	select) #ACTION SELECT
	    NB_PARAM=$(($NB_PARAM+1));
	    ACTION=3;
	    shift;
	    NB_PARAM=$(($NB_PARAM+1));
	    KEY="";
	    if [ "$1" != "" ] && [ "`echo $1 | cut -c1`" != "-" ]; then
		KEY=$1;
	    fi
	    if [ "$1" == "-k" ]; then
		DISPLAY=1;
		K_ENABLED=1;
	    fi
	    ;;

	flush) #ACTION FLUSH
	    NB_PARAM=$(($NB_PARAM+1));
	    ACTION=4;
	    ;;
    esac
    shift;
done

if [ $NB_PARAM -lt $NB_PARAM_OLD ]; then
    usage;
fi

if [ -z "$FILE_NAME" ] || [ ! -f "$FILE_NAME" ] || [ ! -r "$FILE_NAME" ] || [ ! -w "$FILE_NAME" ]; then
    echo "No base found : file $FILE_NAME doesn't exist !";
    exit;
fi

case $ACTION in
    1) #ACTION PUT.
	if [ "`echo $KEY | cut -c1`" == "$" ]; then
	    TMP_LINE=`cut -d² -f1 $FILE_NAME | grep -n -w ${KEY#$} | cut -d: -f1`;
	    if [ -z "$TMP_LINE" ]; then
		echo "No such key: There is no key named ${KEY#$}";
		exit;
	    fi
	    KEY=`head -$TMP_LINE $FILE_NAME | tail -1 | cut -d² -f2`;
	fi
	if [ "`echo $VALUE | cut -c1`" == "$" ]; then
	    TMP_LINE=`cut -d² -f1 $FILE_NAME | grep -n -w ${VALUE#$} | cut -d: -f1`;
	    if [ -z "$TMP_LINE" ]; then
		echo "No such key: There is no key named ${VALUE#$}";
		exit;
	    fi
	    VALUE=`head -$TMP_LINE $FILE_NAME | tail -1 | cut -d² -f2`;
	fi
	KEY_LINE=`cut -d² -f1 $FILE_NAME | grep -n "$KEY" | cut -d: -f1`;
	if [ -z "$KEY_LINE" ]; then
	    echo "$KEY²$VALUE" >> $FILE_NAME;
	else
	    sed -i "${KEY_LINE}c${KEY}²${VALUE}" $FILE_NAME;
	fi
	;;

    2) #ACTION DEL.
	if [ "`echo $KEY | cut -c1`" == "$" ]; then
	    TMP_LINE=`cut -d² -f1 $FILE_NAME | grep -n -w ${KEY#$} | cut -d: -f1`;
	    if [ -z "$TMP_LINE" ]; then
		exit;
	    fi
	    KEY=`head -$TMP_LINE $FILE_NAME | tail -1 | cut -d² -f2`;
	fi
	if [ "`echo $VALUE | cut -c1`" == "$" ]; then
	    TMP_LINE=`cut -d² -f1 $FILE_NAME | grep -n -w ${VALUE#$} | cut -d: -f1`;
	    if [ -z "$TMP_LINE" ]; then
		exit;
	    fi
	    VALUE=`head -$TMP_LINE $FILE_NAME | tail -1 | cut -d² -f2`;
	fi
	VALUE2=`grep "$KEY²" $FILE_NAME | cut -d² -f2`;
	if [ "$KEY²$VALUE" == "$KEY²$VALUE2" ]; then
	    KEY_LINE=`grep -n "${KEY}²${VALUE}" $FILE_NAME | cut -d: -f1`;
	    if [ ! -z "$KEY_LINE" ]; then
		sed -i "${KEY_LINE}d" $FILE_NAME;
	    fi
	elif [ "$VALUE" == "²" ]; then
            KEY_LINE=`cut -d² -f1 $FILE_NAME | grep -n -w $KEY | cut -d: -f1`;
            if [ ! -z "$KEY_LINE" ]; then
		sed -i "${KEY_LINE}c${KEY}²" $FILE_NAME;
            fi
	fi
	;;

    3) #ACTION SELECT.
	if [ -z "$KEY" ]; then
	    if [ $DISPLAY == 0 ]; then
		cut -d² -f2 $FILE_NAME;
	    elif [ $DISPLAY == 1 ]; then
		cut -d² -f1-2 $FILE_NAME | sed -e 's/²/=/g';
	    fi
	elif [ "`echo $KEY | cut -c1`" == "$" ]; then
	    KEY_LINE=`cut -d² -f1 $FILE_NAME | grep -n -w ${KEY#$} | cut -d: -f1`;
	    if [ $DISPLAY == 0 ]; then
		DATA=`head -$KEY_LINE $FILE_NAME | tail -1 | cut -d² -f2`;
		if [ ! -z "$DATA" ]; then
		    echo "$DATA";
		fi
	    elif [ $DISPLAY == 1 ]; then
		DATA=`head -$KEY_LINE $FILE_NAME | tail -1 | sed -e 's/²/=/g'`;
		if [ ! -z "$DATA" ]; then
		    echo "$DATA";
		fi
	    fi
	else
	    if [ $DISPLAY = 0 ]; then
		KEY_LINE=`cut -d² -f1 $FILE_NAME | grep -n $KEY | cut -d: -f1`;
		for i in $KEY_LINE
		{
		    DATA=`head -$i $FILE_NAME | tail -1 | cut -d² -f2`;
		    if [ ! -z "$DATA" ] || [ ${#KEY_LINE[@]} == 1 ]; then
			echo "$DATA";
	            fi
		}
	    elif [ $DISPLAY == 1 ]; then
		KEY_LINE=`cut -d² -f1 $FILE_NAME | grep -n $KEY | cut -d: -f1`;
		if [ -z "$KEY_LINE" ]; then
		    A=0;#echo "$KEY=";
		else
		    for i in $KEY_LINE
		    {
			DATA=`head -$i $FILE_NAME | tail -1 | sed -e 's/²/=/g'`;
			if [ ! -z "$DATA" ]; then
			    echo "$DATA";
			fi
		    }
		fi
	    fi
	fi
	;;

    4) #ACTION FLUSH
	echo -n "" > $FILE_NAME;
	;;

    *) #AUTRES CAS
	usage;
	;;
esac