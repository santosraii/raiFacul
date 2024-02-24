import cv2 as cv
import pytesseract as pt

img = cv.imread('text3.png')

# Obter informações sobre as letras na imagem
boxes = pt.image_to_boxes(img, lang='por')
imh, imw = img.shape[0], img.shape[1]

# Lista para armazenar as letras e suas coordenadas
letras_coordenadas = []

for b in boxes.splitlines():
    b = b.split(' ')
    letra, x, y, w, h = b[0], int(b[1]), int(b[2]), int(b[3]), int(b[4])
    letras_coordenadas.append((letra, x, y, w, h))

# Ordenar a lista de letras com base na coordenada x (largura)
letras_coordenadas.sort(key=lambda item: item[1])

# Desenhar retângulos e imprimir as letras na ordem correta
for letra, x, y, w, h in letras_coordenadas:
    cv.rectangle(img, (x, imh - h), (w, imh - y), (0, 0, 255), 1)
    cv.putText(img, letra, (x, imh - y + 18), cv.FONT_HERSHEY_SIMPLEX, 0.65, (0, 0, 255), 2)

cv.imshow('image', img)
cv.waitKey(0)
