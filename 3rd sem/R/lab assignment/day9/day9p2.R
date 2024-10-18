# Perform Agglomerative Hierarchical Clustering using single linkage
agn_single <- agnes(data, stand=TRUE, diss=FALSE, method="single")

# Convert to a dendrogram and plot
dend_agn_single <- as.dendrogram(agn_single)
plot(dend_agn_single, main = "Single Linkage Dendrogram")
