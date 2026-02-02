# 개요
- representHW git에 있는 hardware IR을 이용하여 원하는 플랫폼으로 연결하여 컴파일러를 빌드하는 프로젝트
- 현재는 IREE를 지원하는 환경만 구성됨

# IREE build with test HWIR & compile model example

## 0. 환경

- python3.11 환경 (venv를 이용하여 환경 구성)
- torch-mlir 설치
- onnx, protobuf 설치
```
$ pip install --pre torch-mlir torchvision \
      --extra-index-url https://download.pytorch.org/whl/nightly/cpu \
      -f https://github.com/llvm/torch-mlir-release/releases/expanded_assets/dev-wheels \
      onnx protobuf
```

## 1. build

- ninja를 이용하여 make 파일을 생성
```
$ cmake -G Ninja -B ./build -S third_party/iree   \
        -DIREE_CMAKE_PLUGIN_PATHS=$PWD   \
        -DIREE_BUILD_PYTHON_BINDINGS=OFF   \
        -DIREE_INPUT_STABLEHLO=ON   \
        -DIREE_INPUT_TORCH=ON   \
        -DIREE_INPUT_TOSA=OFF   \
        -DIREE_HAL_DRIVER_DEFAULTS=ON   \
        -DIREE_TARGET_BACKEND_DEFAULTS=OFF   \
        -DIREE_TARGET_BACKEND_LLVM_CPU=ON   \
        -DIREE_BUILD_TESTS=ON   \
        -DIREE_BUILD_SAMPLES=OFF  \
        -DTARGET_DEVICE="HW1"
```


- build
```
$ cmake --build ./build -j$(nproc)
```



## 2. compile용 모델 준비
- iree에 들어갈 수 있는 형태의 mlir로 변환 (torch mlir, TOSA, stableHLO)
- iree의 툴을 이용하기 위해 공식으로 release된 iree의 툴 설치
```
$ python -m pip install \
  iree-base-compiler[onnx] \
  iree-base-runtime
```

- onnx 모델 변환 : 아래를 실행하면 torch-mlir의 mlir이 생성됨
```
$ iree-import-onnx \
  [model.onnx] \
  --opset-version 17 \
  -o [model.mlir]
```


## 3. 모델 컴파일
- 최종 바이너리는 .vmfb 파일이다.
- 아래는 컴파일과 동시에 이 환경을 활용하여 개발하기 위해 모든 변환패스 적용과정을 프린트하도록 설정되어 있음.
```
$ cd ./build/tools/
$ ./iree-compile [your_model.mlir] \
--iree-hal-target-backends=keti_hw1 \
--mlir-print-ir-after-all \
--mlir-disable-threading \
--compile-to=executable-targets \
--iree-global-opt-experimental-disable-conv-generalization \
--iree-opt-generalize-matmul=false \
--mlir-elide-elementsattrs-if-larger=32 \
-o [your_out_binary.vmfb] > [your_full_pipeline.mlir] 2>&1
```
















































