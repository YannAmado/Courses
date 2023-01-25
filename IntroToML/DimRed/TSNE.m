function [] = TSNE(X, Y)
    M = tsne(X);
    gscatter(M(:,1), M(:,2), Y)
    xlabel('x-axis')
    ylabel('y-axis')
    title('t-SNE using 40 dimensions')
    lgd = legend();
    lgd.Title.String = 'Image number';
end