import cv2 as cv
import numpy as np

# Carrega a imagem
img = cv.imread('paintingruido.jpeg')

# Aplica o filtro de média para remover ruído
smoothed_img = cv.medianBlur(img, 3)  # O segundo argumento é o tamanho do kernel (área da média)

# Exibe as imagens original e suavizada
cv.imshow('Imagem Original', img)
cv.imshow('Imagem Suavizada', smoothed_img)
cv.waitKey(0)

