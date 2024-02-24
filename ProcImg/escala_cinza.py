from PIL import Image
import cv2 as cv

def media_grayescale(colored):
    w, h = colored.size
    img = Image.new("RGB", (w, h))

    for x in range(w):
        for y in range(h):
            pxl = colored.getpixel((x,y))
            gray = (pxl[0] + pxl[1] + pxl[2])//3
            img.putpixel((x,y), (gray, gray, gray))
    return img

def grayescale(colored):
    w, h = colored.size
    img = Image.new("RGB", (w, h))

    for x in range(w):
        for y in range(h):
            pxl = colored.getpixel((x,y))
            gray = int(0.3*pxl[0] + 0.59*pxl[1] + 0.11*pxl[2])
            img.putpixel((x,y), (gray, gray, gray))
    return img

if __name__ == "__main__":
    img = Image.open("carol.jpg")
    print(img.getpixel((100, 100)))
    print(img.getpixel((200, 300)))
    print(img.getpixel((500, 100)))

    baloes = Image.open("carol.jpg")
    gray = grayescale(baloes)
    gray.save("carolgray.jpg")     

"""src = cv.imread("livro.jpg")
window_name = 'Image'
image = cv.cvtColor(src, cv.COLOR_BGR2GRAY)
cv.imshow(window_name, image)
cv.waitKey(0)"""