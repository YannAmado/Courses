function N = regionQuery(D,P,eps)
    
    N = [];
    
    for i=1:size(D,1)
        if pdist2(D(i,:),P) <= eps
            N = [N;D(i,:) i]; %i is the row number of data point
        end
    end
end
