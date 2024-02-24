from PIL import Image
import pytesseract
import cv2 as cv

# Load the image
img = Image.open('ilegivel.jpg')

# Create a copy of the original image
im2 = img.copy()

# Convert the image to grayscale
gray_img = im2.convert('L')

# Create a rectangular kernel for dilation
rect_kernel = cv.getStructuringElement(cv.MORPH_RECT, (15,15))

# Apply dilation to the median blurred image
dilation = cv.dilate(gray, rect_kernel, iterations = 1)

#Find contours
contours, hierarchy = cv.findContours(gray_img, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)

# Threshold
gray_img = gray_img.point(lambda x: 0 if x<128 else 255, '1')

# Save the thresholded image
gray_img.save('ilegivel2.jpg')

# Recognize text in the image using pytesseract
text = pytesseract.image_to_string(gray_img)
print(text)
"""
# Write the recognized text to the file
file = open("recognized.txt", "w")
file.write(text)
file.close()"""
# Draw the bounding boxes on the image
# boxes = pytesseract.image_to_boxes(gray_img)
# for b in boxes.splitlines():
#     b = b.split(' ')
#     img = Image.open('ilegivel.jpg')
#     draw = ImageDraw.Draw(img)
#     draw.rectangle([int(b[1]), int(b[2]), int(b[3]), int(b[4])])
#     img.save('ilegivel3.jpg')
#     img.show()
#     img.close()
#     # Draw the bounding boxes on the image
