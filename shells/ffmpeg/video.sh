#!/bin/bash

function conv() {
	local infile=$1
	local outfile=$2
	ffmpeg  -i ${infile} -c:v libx264 -preset veryfast  -s 1920x1080 -r 25  -b:v 1500k  -bufsize 1500k -maxrate 1500k -minrate 1500k -rc_init_occupancy 1125k  -max_delay 1.4M  -profile:a aac_low  -b:a 192k  -ar 44100 -ac 2 -muxrate 2000k -f mpegts -max_interleave_delta 1000000  ${outfile}
}

for file in `ls *.mp4`
do
	conv ${file} "new-${file}"
done
