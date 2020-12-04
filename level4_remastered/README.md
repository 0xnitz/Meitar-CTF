# Level4 Remastered

If you participated in my last challenge and got to level 4, you've encountered a very weird jpg image that contained a string of the password.
That challenge was actually a zipfile combined with an image.

This time to make the challenge harder I encrypted the zip file so strings won't help ya'll :0

```bash
strings puppy.jpeg
```

will reveal the flag.txt file and the zip file format header.

Changing the extension to zip or running binwalk will reveal a zip with a password and using the hint supplied in the challenge description you can get the flag!

password: meitar

**MEITAR{f1le_f0rm4ts_ar3_h4rd}**