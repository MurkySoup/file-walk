# file-walk
List contents of a filesystem hierchy with costly stat() overhead!

The original use-case was to scan an EXT3 filesystem hierarchy that had been overrun with millions of files, slowing normal use to a crawl. This program generated the file list necessary to target and delete the offending files (which were most offensive, indeed)!

## Build instructions:
You'll need GCC. There are numerous tutorials online to assist you with this step, if you're new to the GCC toolchain. Use the included 'make' file. This program should compile easily using GCC 3.x+, but might require installation of GLIBC static libraries, if they're not already present.

Example given:
```
$ make
```

You may then copy the compiled executable to an accessible point inside your execution path.

## Example use:
```
$ file-walk /path/to/hierarchy
```

During internal testing, this program delivered a list from a hierarchy containing 41K+ directories and 135K+ files in under three seconds.

**Be aware: This program will recursively walk an entire hierarchy from the starting point you give. There is no option built into this program to limit or alter this behavior. It will also have a major memory footprint if used against really large hierarchies.**

I would suggest 'wrapping' this script in a proper control structure. In the following example, if 'file-walk' indicated that a given entry is a file (field one is an "f"), then display the remainder of the line (to correct for spaces, etc., in a given filename), and use 'xargs' to 'stat' files in the resulting list.

```
$ file-walk /path/to/hierarchy | awk '$1 == "f" {for (i=2; i<=NF; i++) print $i}' | xargs stat -t
```

Or to delete a list of files that exceed globbing limites:

```
$ file-walk /path/to/hierarchy | awk '$1 == "f" {for (i=2; i<=NF; i++) print $i}' | xargs rm
```

You can use a bit of imagimation and alter this control structure for a wide array of uses. "Wow" your friends. Impress your boss. Walk like a rock star.

## Built With
* [Gnu Compiler Collection (GCC)](https://gcc.gnu.org)

## Contributing
Please contact the Security Enginnering Team for details on our code of conduct, and the process for submitting pull requests to us.

## Authors
* **Rick Pelletier** - [Gannett Co., Inc. (USA Today Network)](https://www.usatoday.com/)

## License
Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
