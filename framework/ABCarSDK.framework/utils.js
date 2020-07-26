window.Hybrid = {
    
    goBack: function () {
        dsBridge.call("close", function (res) {
            console.log(res)
        })
    },

    share: function (params) {
        var requestData = params
        dsBridge.call("share", requestData, function (res) {
         console.log(res)
        })
    },

    telephone: function (num) {
        var requestData = {
            "phoneNumber": num
        }
        dsBridge.call("telephone", requestData, function (res) {
            console.log(res)
        })
    },

    telephoneList: function (params) {
        var requestData = {
            "phoneNumberList": params
        }
        dsBridge.call("telephoneList", requestData, function (res) {
            console.log(res)
        })
    },

    login: function () {
        dsBridge.call("login", function (res) {
            console.log(res)
        })
    },

    goMapNavi: function (params) {
        var requestData = params
        dsBridge.call("mapNavi", requestData, function (res) {
            console.log(res)
        })
    },

    paySuccess: function () {
        dsBridge.call("paySuccess", function (res) {
            console.log(res)
        })
    },

    getCameraAuthority: function () {
        var res = dsBridge.call("getCameraAuthority", "hello")
        console.log(res)
        return res
    },

    getPhotoLibraryAuthority: function () {
        var res = dsBridge.call("getPhotoLibraryAuthority", "hello")
        console.log(res)
        return res
    },
    getAppVersion: function () {
        var res = dsBridge.call("getAppVersion","hello")
        console.log(res)
        return res
    },

    reOrderAction: function (params) {
        var requestData = {
            "targetUrl": params.redirectUrl,
            "goodsId": params.goodsId
        }
        dsBridge.call("newAction", requestData, function (res) {
            console.log(res)
        })
    },

    openWebView: function (params) {
        var requestData = params
        dsBridge.call("newAction", requestData, function (res) {
            console.log(res)
        })
    },
    
    reloadWebView: function (params) {
        var requestData = params
        dsBridge.call("reloadWebView", requestData, function (res) {
                      console.log(res)
                      })
    },
    
    getAccessToken: function() {
        var res = dsBridge.call("getAccessToken","hello")
        console.log(res)
        return res
    },


}
