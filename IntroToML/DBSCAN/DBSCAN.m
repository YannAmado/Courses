function [cluster] = DBSCAN(D,eps,MinPts)


    cluster = zeros(size(D,1),1);
    visited = zeros(size(D,1),1);

    C = 0;

    for i=1:size(D,1)
        if visited(i) == 0
            visited(i) = 1;
            NeighborPts = regionQuery(D,D(i,:),eps);

            if size(NeighborPts,1) < MinPts
                cluster(i) = -1;
            else
                C = C + 1;
                [visited,cluster] = expandCluster(D,[D(i,:) i],NeighborPts,C,eps,MinPts,visited,cluster);
            end
        end

     end


end