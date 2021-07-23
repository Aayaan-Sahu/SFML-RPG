# Copying another person's engine to make my own game

## Link to playlist for engine - https://www.youtube.com/watch?v=IdKZpv6xqdw&list=PL6xSOsbVA1ebkU66okpi-KViAO8_9DJKg

## Build Dependencies
* Python3 - version higher than 3.6
* colored module for python3 - Install -> `pip3 install colored`
* make
* g++
* SFML

## Setup SFML - Mac
1. `brew install sfml`
2. In your `.bashrc` / `.zshrc`:
	* `export CPLUS_INCLUDE_PATH=/usr/local/Cellar/sfml/2.5.1_1/include/:$CPLUS_INCLUDE_PATH`
3. `source .bashrc` / `source .zshrc`

## Build Instructions
1. Clone the repo: `git clone https://github.com/Aayaan-Sahu/SFML-RPG`
2. Build the executable: `make build`
3. Run the executable: `bin/Application`

## If you don't want to build
* Just run `bin/Application`
