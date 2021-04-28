I had to install PyQRCode and Pillow, to do that I used these two commands:
pip install Pillow
pip install pyqrcode

To run my program, use this command:
python franz-MP4.py --get-otp OR --generate-qr

This is what I did, but I heard of other people using a virtual environment, I hope this is okay.

Brief Explanation:
To generate the QRCode, I set the URL by following the Key Uri Format on the google-authenticator GitHub
page that was linked in the assignment sheet. After creating the QRCode, it is saved as an SVG file.

To generate the OTP, I converted the secret key using base64.b32decode so that hmac.new() could use it.
After that, I got the Unix Time and converted it into a byte array. Then I created the hmac. 
After creating the hmac, I truncate it using the offset that is the last digit. I then grabbed the first
4 bytes after the offset. Then I applied a binary operation to all of the bytes at once. After that, I
print out the last 6 digits which is the OTP we're looking for.
