# Hash-generator

:hash: It is a simple program, which generates unique hash code of any size of text :hash:

**The hash function complies all the requirements that were specified in the given task:**
* Input can be of any size  :heavy_check_mark:
* Output will always be in fixed length  :heavy_check_mark:
* Hash function is deterministic (output of the same input is also the same)  :heavy_check_mark:
* Hash function is fast  :heavy_check_mark:
* It is impossible to recover text from a hash code  :heavy_check_mark:
* Hash function is collision resistant  :heavy_check_mark:

**This is how hash function works:** :snail:

* Converts text into binary code
* Padds the binary code if it's size is less than 256
* Uses logic gates (most of them are XOR) to mix all the binary code (makes hash code irrecoverable)
* Converts binary to hexadecimal code

**Proof of avalanche effect:** : :volcano:

(It seems that the output does not have fixed length, but trust me, all of them consist of 64 symbols, you can count if you want :) )

|   Input    |                         Output                                     |
|------------|--------------------------------------------------------------------|
|  lietuva   |  dbb2e6f7e020bebaaebe8203f7b3a6edb765cdefc0417d755086e2dc54a3a78f  | 
|  Lietuva   |  c0df49d2ed8f9aa222acf8dba5c97d8181be93a5db1f354446fd2fca2f6eb3df  |
|  Lietuva!  |  d523cbd8a626c29634a1b2328de9e2556a4797b14c4d852c33bede1b07b67d15  |


**Analysis**

Files with one symbol inside:

|  File name  |   Time consumed   |                       Output                                     |
|-------------|-------------------|------------------------------------------------------------------|
|oneSymb1.txt |      1.013ms      | 0b4af3b3ed33142dda14665be6e7a9681695e767da66285b158ab714dab644d0 |
|oneSymb1.txt |      1.002m       | d08ca5ec908ca5ec1bd298849bd298855ee6b426dee6b427de29f755de29f754 |


Large files (1001 symbols):

|  File name  |   Time consumed   |                       Output                                     |
|-------------|-------------------|------------------------------------------------------------------|
|  long1.txt  |      1.999ms      | 06ee6dd453927e8d8fb48b3946a9d2735206567c4fda27aa58e82ad190435b8a |
|  long2.txt  |      2.008ms      | cadcf12a2e866f6673f4e4a1a04f9c1baa8f2b78cf2ad46f2df591402840db9e |

Large files (1001 symbols and only one symbol is different):

|      File name         |   Time consumed   |                       Output                                     |
|------------------------|-------------------|------------------------------------------------------------------|
|  longOneSymbDiff1.txt  |      2ms          | 582ef6beb9a38e4c647c0641981b61e3b9207fbea309c604b82f0c54579eba7e |
|  longOneSymbDiff2.txt  |      1.997ms      | cc7fb3aae8e69a1d216857048c4a24f7e8656befe61d9741ac7e494006dbae2f |

Konstitucija.txt file analysis:

|      File name         |   Time consumed   |                       Output                                     |
|------------------------|-------------------|------------------------------------------------------------------|
|  Konstitucija.txt      |    110.936m       | 5ac9ee5b181ec70630269c9e7e1c1df865660c8ce72d557c941e4950abb9508a |

Check for collisions (test1):

|    length of line      |   Collisions found  |
|------------------------|---------------------|
|    10                  |         0           |
|    100                 |         0           |
|    500                 |         0           |
|    1000                |         0           |
