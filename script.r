my_data <- read.table("/home/marcmarcos/Desktop/PE-BloqueT/output_grande.txt", header=TRUE)
split_data <- split(my_data, my_data$Arbol)

my_data$Tiempo 

qqnorm(split_data$AVL$Tiempo, pch = 1, frame = FALSE, main="Q-Q Plot AVL")
qqline(split_data$AVL$Tiempo, col = "steelblue", lwd = 2)

qqnorm(split_data$SplayTree$Tiempo, pch = 1, frame = FALSE, main="Q-Q Plot AVL")
qqline(split_data$SplayTree$Tiempo, col = "steelblue", lwd = 2)

qqnorm(split_data$RedBlack$Tiempo, pch = 1, frame = FALSE, main="Q-Q Plot RedBlack")
qqline(split_data$RedBlack$Tiempo, col = "steelblue", lwd = 2)

qqnorm(my_data$Tiempo, pch = 1, frame = FALSE, main="Q-Q Plot All Trees")
qqline(my_data$Tiempo, col = "steelblue", lwd = 2)

data_list <- list(AVL = split_data$AVL$Tiempo, SplayTree = split_data$SplayTree$Tiempo, RedBlack = split_data$RedBlack$Tiempo)

# Create a boxplot for each vector
boxplot(data_list, col = c("red", "green", "blue"), names = c("AVL", "SplayTree", "RedBlack"),
        main = "Boxplots", ylab = "Tiempo")

split_data_AVL = split(split_data$AVL, split_data$AVL$Modo)

split_data_SplayTree = split(split_data$SplayTree, split_data$SplayTree$Modo)

split_data_RedBlack = split(split_data$RedBlack, split_data$RedBlack$Modo)

data_list_balanced = list(AVL = split_data_AVL$balanced$Tiempo, split_data_SplayTree$balanced$Tiempo, split_data_RedBlack$balanced$Tiempo)

boxplot(data_list_balanced, col = c("red", "green", "blue"), names = c("AVL", "SplayTree", "RedBlack"),
        main = "Boxplots con input balanceado", ylab = "Tiempo")


data_list_search = list(AVL = split_data_AVL$searches$Tiempo, split_data_SplayTree$searches$Tiempo, split_data_RedBlack$searches$Tiempo)

boxplot(data_list_search, col = c("red", "green", "blue"), names = c("AVL", "SplayTree", "RedBlack"),
        main = "Boxplots con input con busquedas predominantes", ylab = "Tiempo")


data_list_delete = list(AVL = split_data_AVL$deletes$Tiempo, split_data_SplayTree$deletes$Tiempo, split_data_RedBlack$deletes$Tiempo)

boxplot(data_list_delete, col = c("red", "green", "blue"), names = c("AVL", "SplayTree", "RedBlack"),
        main = "Boxplots con input con eliminados predominantes", ylab = "Tiempo")


data_list_insert = list(AVL = split_data_AVL$inserts$Tiempo, split_data_SplayTree$inserts$Tiempo, split_data_RedBlack$inserts$Tiempo)

boxplot(data_list_insert, col = c("red", "green", "blue"), names = c("AVL", "SplayTree", "RedBlack"),
        main = "Boxplots con input con inserts predominantes", ylab = "Tiempo")