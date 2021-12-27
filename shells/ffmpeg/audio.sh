#!/bin/bash
## ffmpeg is a simple commandline based media processing tool.
## this shell scripts mainly for you to convert audio files
#   STILL BUGS FOR PROCESSING FILES WITH MORE THAN ONE DOT IN FILE NAME
#
INPUT_DIR=$1
OUTPUT_DIR=$2

to_mp3() {
    ffmpeg -i $1  -b:a 256k -acodec mp3 -ar 44100 -ac 2 "$2"
}

get_file_name() {
    FILE=$1
    echo "${FILE%%.*}.mp3"
}

cd ${INPUT_DIR}
[ ! -d ${OUTPUT_DIR} ] && mkdir -p ${OUTPUT_DIR}

IFS=$(echo -en "\n\b")
for music in *
do  
    if [ ! -d $music ]; then 
        file_name="`get_file_name ${music}`.mp3"
        to_mp3 ${music} "${file_name}"
        mv ${file_name} "${OUTPUT_DIR}/${file_name%.*}"
    fi
done


