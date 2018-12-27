# fstore
There are some files which can be required quite often. Using this tool you can store your files and place them quickly in any directory you want.

## Installation

Firstly you should clone this repository in any directory you want.

```
git clone https://github.com/NikitaKemarskiy/fstore.git
```

Then you should install it into your system using the next command:

```
sudo make install
```

## Usage

To save your file into the storage, open the directory when your file is located. Then execute this command:

```
sudo fstore --save [FILENAME]
```

You can save your file with the new name:

```
sudo fstore --save [FILENAME] --name [NEW FILENAME]
```

To insert your file from the storage to your current working directory use the next command:

```
fstore --get [FILENAME]
```
<<<<<<< HEAD

To remove your file from the storage use the next command:

```
fstore --remove [FILENAME]
```