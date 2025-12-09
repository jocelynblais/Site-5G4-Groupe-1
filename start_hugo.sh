#!/bin/sh

docker run -it -p 8080:8080 --rm --volume ${PWD}:/src hugo_relearn:latest bash -c "cd /src ; rm -rf public; hugo serve -p 8080 --bind 0.0.0.0 $1"
