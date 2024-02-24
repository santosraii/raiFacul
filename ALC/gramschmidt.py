import numpy as np

def gram_schmidt_qr(A):
    m, n = A.shape
    Q = np.zeros((m, n))
    R = np.zeros((n, n))

    for j in range(n):
        v = A[:, j]
        for i in range(j):
            R[i, j] = np.dot(Q[:, i], A[:, j])
            v = v - R[i, j] * Q[:, i]
        R[j, j] = np.linalg.norm(v)
        Q[:, j] = v / R[j, j]

    return Q, R

def recommend_movies_qr(A, user_ratings):
    Q, R = gram_schmidt_qr(A)
    Q_transpose = Q.T
    R_inv = np.linalg.inv(R)
    X = np.dot(R_inv, np.dot(Q_transpose, user_ratings))

    return X

# Exemplo de uso:
#A = np.array([[5, 3, 0, 0, 4],
  #            [4, 0, 4, 0, 3],
   #           [5, 3, 3, 0, 5],
    #          [0, 4, 0, 5, 4],
     #         [0, 0, 5, 4, 5]])

#user_ratings = np.array([4, 0, 0, 5, 0])
#recommended_movies = recommend_movies_qr(A, user_ratings)
#print("Recomendação de filmes/séries:", recommended_movies)/*

ratings = np.array([[5, 4, 5, 0, 0],
                    [3, 0, 3, 4, 0],
                    [0, 4, 3, 0, 5],
                    [0, 0, 0, 5, 4]])

# Realiza a decomposição QR da matriz de avaliações
Q, R = np.linalg.qr(ratings)

# Fatores latentes (usuários e filmes) são as colunas de Q e as linhas de R
latent_factors_users = Q
latent_factors_items = R.T

# Calcula as previsões de avaliações para todos os usuários e filmes
predicted_ratings = np.dot(latent_factors_users, latent_factors_items.T)

# Recomendação para um usuário específico (usuário 0, por exemplo)
user_id = 0
user_ratings = predicted_ratings[user_id, :]
sorted_movie_indices = np.argsort(user_ratings)[::-1]  # Ordena em ordem decrescente

print("Recomendação para o usuário", user_id)
for i in range(len(sorted_movie_indices)):
    movie_index = sorted_movie_indices[i]
    print("Filme", movie_index, "- Previsão de avaliação:", user_ratings[movie_index])