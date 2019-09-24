# To Build: docker build --no-cache -t pbui/cse-30872-fa18-assignments . < Dockerfile

FROM	    alpine:3.8
MAINTAINER  Peter Bui <pbui@nd.edu>

RUN	    apk update

# Run-time dependencies
RUN	    apk add make python3 py3-tornado py3-requests py3-yaml
