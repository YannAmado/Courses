function [] = clustering(X)
    X = sortrows(X, 1);
    methods = {'single', 'average', 'complete', 'ward'};
    % ploting the dendrograms
    for i = 1:length(methods)
        Xlinked = linkage(X, methods(i));
        dendrogram(Xlinked);
        clusteredX = cluster(Xlinked,'maxclust', 4);
        gscatter(X(:,1), X(:,2), clusteredX)
        hold on;
    end

end