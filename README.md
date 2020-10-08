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

