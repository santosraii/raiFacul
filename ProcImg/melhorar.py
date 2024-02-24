import cv2
import numpy as np

imagem = cv2.imread("livro.jpg")
forma = imagem.shape
altura = forma[0]
largura = forma[1]
#canais de cores em forma BGR (blue, green, red)
cores = forma[2]
c = 50

imagem_filtrada = np.maximum(0, imagem - c)

cv2.imshow("Imagem Original", imagem)
cv2.imshow("Imagem Filtrada", imagem_filtrada)
while(1):
    cv2.waitKey(0)