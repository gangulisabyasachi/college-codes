# Load necessary library
install.packages("cluster")
library(cluster)

# Read the data file
data <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/UtilitiesLab.csv")

# Perform Agglomerative Hierarchical Clustering using complete linkage
agn <- agnes(data, stand=TRUE, diss=FALSE, method="complete")

# Convert to a dendrogram and plot
dend_agn <- as.dendrogram(agn)
plot(dend_agn, main = "Complete Linkage Dendrogram")
