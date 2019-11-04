install.packages("fpc")
install.packages("rjson")
install.packages("data.table")
install.packages("ggplot2")
install.packages("dbscan")
install.packages("factoextra")

library(fpc)
library(rjson)
library(data.table)
library(ggplot2)
library(cluster)
library(dbscan)

######################## Read json ###############################

json_row_data <- fromJSON(file = "file:///C:/R/dataset/json/mini_data.json")
json_row_data <- rbindlist(json_row_data)

######################## Read Excel ###############################

json_row_data <- read.csv("file:///C:/R/dataset/csv/new_dataset.csv",header=TRUE, stringsAsFactors=default.stringsAsFactors())

####################### Machine Learning ##########################

dataset <- json_row_data[]
data_matrix <- as.matrix(dataset[-1])

# Find EPS
kNNdistplot(data_matrix, k=10)
abline(h=0.4, col="red")

############################# DBSCAN
set.seed(1234)
dbscan.result <- dbscan(data_matrix,0.45,3)
dbscan.result

# Visualization
png(filename = "test.png", width = 800, height = 600)
hullplot(data_matrix, dbscan.result$cluster)
dev.off()
#########################################

############################# Another DBSCAN
str(dataset)
# Convert DataType
dataset$Protocol <- as.numeric(factor(dataset$Protocol))
dataset$Src_MAC <- as.numeric(factor(dataset$Src_MAC))
dataset$Dst_MAC <- as.numeric(factor(dataset$Dst_MAC))
dataset$Src_IP <- as.numeric(factor(dataset$Src_IP))
dataset$Dst_IP <- as.numeric(factor(dataset$Dst_IP))
dataset$Http_Type <- as.numeric(factor(dataset$Http_Type))
dataset$Http_Method <- as.numeric(factor(dataset$Http_Method))

dbscan.result <- fpc::dbscan(dataset[0:22], eps=0.42, MinPts=10)
dbscan.result
cluster_data <- data.frame(dbscan.result$cluster)

index = 2
while(index <= 22)
{
  file_name = paste0("C:\\R\\result\\",as.character(index),".png")
  png(filename = file_name, width = 800, height = 600)
  plot(dbscan.result, dataset[c(2,index)])
  dev.off()
  index = index + 1
}


# Visualization
png(filename = "test.png", width = 800, height = 600)
hullplot(data_matrix, dbscan.result$cluster)
dev.off()
#########################################


# Plot Visualization
plot(dbscan.result, data_matrix[c(1,24)])
plot(dbscan.result, dataset[c(2,4)])

####################### Save ######################################

# write.csv(cluster_dataset, file="file:///C:/R/dataset/csv/dataset.csv", row.names= FALSE)



