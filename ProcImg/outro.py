
import cv2 as cv
import pytesseract

img = cv.imread('text2.png')

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

rect_kernel = cv.getStructuringElement(cv.MORPH_RECT, (15,15))

dilation = cv.dilate(gray, rect_kernel, iterations = 1)

contours, hierarchy = cv.findContours(dilation, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_NONE)

im2 = img.copy()

file = open("recognized.txt", "w+")
file.write("")
file.close()

word_count = 0

for cnt in contours:

    x, y, w, h = cv.boundingRect(cnt)
   
    cv.rectangle(im2, (x, y), (x + w, y + h), (0, 255, 0), 2)

    cropped = im2[y:y + h, x:x + w]

    text = pytesseract.image_to_string(cropped)
    
    words_in_line = text.split()
    word_count += len(words_in_line)
    print(text)
    
    file = open("recognized.txt", "a")
    file.write(text)
    file.write("\n")
    file.close()

cv.imshow('Final result', im2)
print("Total words: " + str(word_count))

cv.waitKey(0)
