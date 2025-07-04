FROM continuumio/miniconda3

# 安装必要工具
RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    cmake \
    libgomp1 \
    libopenmpi-dev \
    openmpi-bin \
    && rm -rf /var/lib/apt/lists/*

# 创建工作目录
WORKDIR /workspace

# 拷贝 conda 配置并创建环境
COPY environment.yml .
RUN conda env create -f environment.yml
ENV PATH /opt/conda/envs/fem_env/bin:$PATH

# 拷贝代码
COPY . .

# 使用 CMake 构建
RUN mkdir -p build && cd build && cmake .. && make
CMD ["./build/main"]
