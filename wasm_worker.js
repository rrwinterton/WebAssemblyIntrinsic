var g_importObject = { 
  'env': { 
    'memoryBase': 0,
    'tableBase': 0,
    'memory': new WebAssembly.Memory({ initial: 256 }),
    'table': new WebAssembly.Table({ initial: 0, element: 'anyfunc' })
  }
};

var g_objInstance = null;
self.onmessage = function (evt) {
  var objData = evt.data;
  var sMsgId = objData.MsgId;
  if (sMsgId === "RunTests") {
    var iResult = g_objInstance.exports.wasmMain(objData.Start, objData.End);
    self.postMessage(`Starting test: ${objData.Start.toString()}, Ending test: ${objData.End.toString()}, Result: ${iResult.toString()}.`); 
  }
  else if (sMsgId === "CompiledModule") {
    WebAssembly.instantiate(objData.WasmModule, g_importObject).then(instance =>
      g_objInstance = instance);
  }
}
