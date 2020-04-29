% test.m

m = 10000;
for gpu_use = 0:1
    A = gpu(randn(m,m), gpu_use);
    B = gpu(randn(m,m), gpu_use);
    a = rem(randperm(10*m), m)+1;
    f1 = @() A*B;
    f2 = @() A(a,:);
    if gpu_use == 1
        gputimeit(f1)
        gputimeit(f2)
    else
        timeit(f1)
        timeit(f2)
    end
end


function test = gpu(M, gpu_use)
    if gpu_use == 1
        M = gpuArray(M);
    end
end
