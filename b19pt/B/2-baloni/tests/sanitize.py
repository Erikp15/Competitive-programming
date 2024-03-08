#! /usr/bin/python
"""
Strips lines
Deletes empty lines
"""
import os
import sys

os.system("chmod 644 *.in *.sol")
if __name__ == '__main__':
    for filename in os.listdir("."):
        if os.path.isdir(filename) or filename.startswith(sys.argv[0]):
            continue
        input = open(filename)
        newfile = open("%s.new" % filename, "w")
        for line in filter(
                        lambda x:x!='',
                        map(str.rstrip, input.readlines())
                    ):
            newfile.write('%s\n'%line)
        newfile.close()
        input.close()
        os.system("mv %s.new %s" % (filename, filename))
