function [visited,cluster] = expandCluster(D,P,NeighborPts,C,eps,MinPts,visited,cluster)
    cluster(P(1,3)) = C;

    j=1;
    flag=1;
    while flag
        if visited(NeighborPts(j,3))==0
            visited(NeighborPts(j,3))=1;

            NeighborPts2 = regionQuery(D,NeighborPts(j,1:2),eps);
            if size(NeighborPts2,1)>=MinPts
                
                for i=1:size(NeighborPts2,1)
                    temp = 0;
                    for k=1:size(NeighborPts,1)
                        if NeighborPts2(i,3)==NeighborPts(k,3)
                            temp = temp +1;
                            break;
                        end
                    end
                    if temp==0
                       NeighborPts=[NeighborPts;NeighborPts2(i,:)];
                    end
                end

            end

         
        end

        if cluster(NeighborPts(j,3))==0
            cluster(NeighborPts(j,3))=C;
        end
        j=j+1;

        if j>size(NeighborPts,1)
            flag=0;
        end
        
    end
    

end