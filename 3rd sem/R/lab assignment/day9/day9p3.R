# Perform Agglomerative Hierarchical Clustering using average linkage
agn_avg <- agnes(data, stand=TRUE, diss=FALSE, method="average")

# Convert to a dendrogram and plot
dend_agn_avg <- as.dendrogram(agn_avg)
plot(dend_agn_avg, main = "Average Linkage Dendrogram")
