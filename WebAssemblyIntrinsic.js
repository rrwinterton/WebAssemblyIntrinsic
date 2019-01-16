function InitWasmWorker(g_WebWorker) {
        g_WasmWorker.onerror = function (evt) { console.log(`WASM Worker Error: ${evt.message}`); }
        g_WasmWorker.onmessage = function (evt) { alert(`WASM Worker:\n\n ${evt.data}`); }
        fetch("WebAssemblyIntrinsic.wasm").then(response =>
          response.arrayBuffer()
        ).then(bytes =>
          WebAssembly.compile(bytes)
        ).then(WasmModule =>
          g_WebWorker.postMessage({ "MsgId": "CompiledModule", "WasmModule": WasmModule })
        );
}
