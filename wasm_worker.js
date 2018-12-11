var importObject = {
  imports: {
    imported_func: function(arg) {
      console.log(arg);
    }
  }
};

    function fetchAndInstantiateWasm (url, imports) {
      return fetch(url)
      .then(res => {
        if (res.ok)
          return res.arrayBuffer();
        throw new Error(`Unable to fetch Web Assembly file ${url}.`);
      })
      .then(bytes => WebAssembly.compile(bytes))
      //.then(module => WebAssembly.instantiate(module, imports || {}))
      .then(instance => instance.exports);
    }

function loadAndRun() {

    fetchAndInstantiateWasm('WebAssemblyIntrinsic.wasm', {
      env: {
        consoleLog: num => console.log("hi")
      }
    })
    .then(module => {
      var returnStatus = 1;
      returnStatus = module.instance.exports.wasmMain();
      console.log("output " + returnStatus.toString()); //"rich"));
    });
}

function loadAndRun2() {
fetch('WebAssemblyIntrinsic.wasm').then(response => 
  response.arrayBuffer()
).then(bytes => 
  WebAssembly.instantiate(bytes)
).then(obj => {
    console.log(obj.instance.exports.wasmMain());
});
}

function loadAndRun1() {

    WebAssembly.instantiateStreaming(fetch('WebAssemblyIntrinsic.wasm'), importObject)
.then(obj => {
  // Call an exported function:
  obj.instance.exports.exported_func();

  // or access the buffer contents of an exported memory:
  var i32 = new Uint32Array(obj.instance.exports.memory.buffer);

  // or access the elements of an exported table:
  var table = obj.instance.exports.table;
  console.log(table.get(0)());
});

}
