
import cv2 as cv
import pytesseract

img = cv.imread('prova1.jpg')

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

rect_kernel = cv.getStructuringElement(cv.MORPH_RECT, (15,15))

dilation = cv.dilate(gray, rect_kernel, iterations = 1)

contours, hierarchy = cv.findContours(dilation, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_NONE)

im2 = img.copy()

file = open("recognized.txt", "w+")
file.write("")
file.close()

for cnt in contours:

    x, y, w, h = cv.boundingRect(cnt)
   
    cv.rectangle(im2, (x, y), (x + w, y + h), (0, 255, 0), 2)

    cropped = im2[y:y + h, x:x + w]

    text = pytesseract.image_to_string(cropped)
    print(text)
    
    file = open("recognized.txt", "a")
    file.write(text)
    file.write("\n")
    file.close()

h, w, c = im2.shape
boxes = pytesseract.image_to_boxes(im2)
for b in boxes.splitlines():
    b = b.split(' ')
    im2 = cv.rectangle(im2, (int(b[1]), h - int(b[2])), (int(b[3]), h - int(b[4])), (0, 255, 0), 1)

cv.imshow('Painting', im2)

cv.waitKey(0)
