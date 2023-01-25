function [Z_d, reducedDim] = PCA(X)
    Z = X - mean(X);
    %if we do not transpose Z, U and Z will not match dimensions
    %i.e not transposed Z the multiplication is dx1024 * 1440x1024
    %as transposed Z is dx1440 * 1440x1024
    C = cov(Z);
    [U, D] = eig(C);
    [D, i] = sort(diag(D), 'descend');
    U = U(:,i);
    varKept = [0.9 0.95 0.98];
    d = 0;
    reducedDim = [0 0 0];
    % reducedData = [zeros(1,1)];
    for i = 1 : 1
        p = 0;
        while p <= varKept(i)
            d = d + 1;
            p = sum(D(1:d), 'all')/sum(D, 'all');
        end
        Z_d = transpose(U(:, 1:d))*transpose(Z);
        Z_d = transpose(Z_d);
        reducedDim(i) = d;
    end
end

