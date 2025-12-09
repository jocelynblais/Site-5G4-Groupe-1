FROM ubuntu:latest

# Install dependencies
RUN apt update && \
    apt install -y wget git

# Download and install Hugo
RUN wget -O /tmp/hugo.deb https://github.com/gohugoio/hugo/releases/download/v0.148.1/hugo_0.148.1_linux-amd64.deb && \
    apt-get install -y /tmp/hugo.deb && \
    rm /tmp/hugo.deb

# Set default command
CMD ["hugo", "version"]