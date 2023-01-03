"Caesar's coding" is one of the best known coding techniques, where each line of the given text is replaced by a different letter at a fixed distance each time in the alphabet. To example, with a shift of 3, A is replaced by D, Z by C.

The function *encrypt(char *str, int dist); creates a new string with the encoded form of the str parameter
The function void decrypt(char *str, int dist); decrypts the string str given as a parameter.

•	Example
./a.out encrypt 4 [This.String.is.not.encrypted] will return [Xlmw.Wxvmrk.mw.rsx.irgvctxih].
