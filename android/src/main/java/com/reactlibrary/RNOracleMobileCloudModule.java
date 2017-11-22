
package com.reactlibrary;

import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.WritableArray;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.bridge.WritableNativeArray;
import com.facebook.react.bridge.WritableNativeMap;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import oracle.cloud.mobile.authorization.AuthorizationAgent;
import oracle.cloud.mobile.authorization.AuthorizationCallback;
import oracle.cloud.mobile.customcode.CustomHttpResponse;
import oracle.cloud.mobile.customcode.GenericCustomCodeClientCallBack;
import oracle.cloud.mobile.exception.ServiceProxyException;
import oracle.cloud.mobile.mobilebackend.MobileBackendManager;
import oracle.cloud.mobile.rest.RestClient;

public class RNOracleMobileCloudModule extends ReactContextBaseJavaModule {

  private final int HTTP_METHOD_GET = 0;
  private final int HTTP_METHOD_POST = 2;
  private final int HTTP_METHOD_DELETE = 3;
  private final int HTTP_METHOD_PUT = 1;
  private AuthorizationAgent auth;
  private final ReactApplicationContext reactContext;

  public RNOracleMobileCloudModule(ReactApplicationContext reactContext) {
    super(reactContext);
    this.reactContext = reactContext;
  }

  @Override
  public String getName() {
    return "RNOracleMobileCloud";
  }

  @Override
  public Map<String, Object> getConstants() {
    final Map<String, Object> constants = new HashMap<>();
    constants.put("HTTP_METHOD_GET", HTTP_METHOD_GET);
    constants.put("HTTP_METHOD_POST", HTTP_METHOD_POST);
    constants.put("HTTP_METHOD_DELETE", HTTP_METHOD_DELETE);
    constants.put("HTTP_METHOD_PUT", HTTP_METHOD_PUT);
    return constants;
  }

  @ReactMethod
  public void loginUser(String user, String password, final Callback callback) {
    try {

      auth =  MobileBackendManager.getManager()
              .getDefaultMobileBackend(reactContext)
              .getAuthorization();

      AuthorizationCallback authorizationCallback = new AuthorizationCallback() {

        @Override
        public void onCompletion(ServiceProxyException exception) {
          if (exception == null) {

            WritableMap map = new WritableNativeMap();
            if(auth.getCurrentUser() != null) {
              map.putString("user", auth.getCurrentUser().getUsername());
              map.putString("email", auth.getCurrentUser().getEmail());
              map.putString("lastName", auth.getCurrentUser().getLastName());
              map.putString("firstName", auth.getCurrentUser().getFirstName());
            }
            callback.invoke(true, map);
          } else {
            callback.invoke(false, exception.getMessage());
          }
        }
      };

      auth.authenticate(getCurrentActivity(), user, password, authorizationCallback);

    } catch (Exception e) {
      e.printStackTrace();
      callback.invoke(false, e.getMessage());
    }
  }

  @ReactMethod
  public void loginAnonymous(final Callback callback) {
    try {
      AuthorizationCallback mLoginCallback = new AuthorizationCallback() {
        @Override
        public void onCompletion(ServiceProxyException exception) {
          if (exception == null) {
            callback.invoke(true, "Successfully authenticated anonymous");
          } else {
            callback.invoke(false, exception.getMessage());
          }
        }
      };

      MobileBackendManager.getManager()
              .getDefaultMobileBackend(reactContext)
              .getAuthorization().authenticateAnonymous(getCurrentActivity(), mLoginCallback);

    } catch (Exception e) {
      e.printStackTrace();
      callback.invoke(false, e.getMessage());
    }
  }


  @ReactMethod
  public void logOut(final Callback callback) {
    try {
      AuthorizationCallback mLoginCallback = new AuthorizationCallback() {
        @Override
        public void onCompletion(ServiceProxyException exception) {
          if (exception == null) {
            callback.invoke(true, "Successfully user logout");
          } else {
            callback.invoke(false, exception.getMessage());
          }
        }
      };

      auth = MobileBackendManager.getManager().getDefaultMobileBackend(reactContext).getAuthorization();
      if(auth != null && auth.isAuthorized())
        auth.logout(getCurrentActivity(), mLoginCallback);
      else
        callback.invoke(false, "There is no user");

    } catch (Exception e) {
      e.printStackTrace();
      callback.invoke(false, e.getMessage());
    }
  }

  @ReactMethod
  public void invokeEndPoint(String apiEndPoint, String body, int httpMethod, final Callback callback) {
    try {
      GenericCustomCodeClientCallBack genericCustomCodeClientCallBack = new GenericCustomCodeClientCallBack() {
        @Override
        public void requestCompleted(CustomHttpResponse response, JSONObject data, Exception exception) {
          if (exception == null) {
            boolean responseStatus = (response.getHttpStatus() >= 200 && response.getHttpStatus() < 300);

            if(responseStatus) {
              WritableMap map = null;
              try {
                map = convertJsonToMap(data);
              } catch (JSONException e) {
                e.printStackTrace();
                callback.invoke(false, e.getMessage());
              }
              callback.invoke(true, map);
            }
            else {
              callback.invoke(false, "httpStatus: " + response.getHttpStatus());
            }
          }
          else {
            callback.invoke(false, exception.getMessage());
          }
        }
      };

      // Get the HTTP
      RestClient.HttpMethod method = getHttpMethod(httpMethod);

      // JSON to String body
      JSONObject dataBody = null;
      if(body != null) {
        dataBody = new JSONObject(body);
      }

      auth = MobileBackendManager.getManager()
              .getDefaultMobileBackend(reactContext)
              .getAuthorization();
      if(auth != null && auth.isAuthorized())
        auth.invokeCustomCodeJSONRequest(genericCustomCodeClientCallBack, dataBody, apiEndPoint, method);
      else
        callback.invoke(false, "You need to login");

    } catch (Exception e) {
      e.printStackTrace();
      callback.invoke(false, e.getMessage());
    }
  }

  private RestClient.HttpMethod getHttpMethod(int type) throws Exception {

    RestClient.HttpMethod method = null;

    switch (type) {
      case HTTP_METHOD_GET:
        method = RestClient.HttpMethod.GET;
        break;
      case HTTP_METHOD_DELETE:
        method = RestClient.HttpMethod.DELETE;
        break;
      case HTTP_METHOD_PUT:
        method = RestClient.HttpMethod.PUT;
        break;
      case HTTP_METHOD_POST:
        method = RestClient.HttpMethod.POST;
        break;
      default:
        new Exception("You must indicate the HttpMethod");
    }
    return method;
  }

  private static  WritableMap convertJsonToMap(JSONObject jsonObject) throws JSONException {
    WritableMap map = new WritableNativeMap();

    Iterator<String> iterator = jsonObject.keys();
    while (iterator.hasNext()) {
      String key = iterator.next();
      Object value = jsonObject.get(key);
      if (value instanceof JSONObject) {
        map.putMap(key, convertJsonToMap((JSONObject) value));
      } else if (value instanceof JSONArray) {
        map.putArray(key, convertJsonToArray((JSONArray) value));
      } else if (value instanceof  Boolean) {
        map.putBoolean(key, (Boolean) value);
      } else if (value instanceof  Integer) {
        map.putInt(key, (Integer) value);
      } else if (value instanceof  Double) {
        map.putDouble(key, (Double) value);
      } else if (value instanceof String)  {
        map.putString(key, (String) value);
      } else {
        map.putString(key, value.toString());
      }
    }
    return map;
  }

  private static WritableArray convertJsonToArray(JSONArray jsonArray) throws JSONException {
    WritableArray array = new WritableNativeArray();

    for (int i = 0; i < jsonArray.length(); i++) {
      Object value = jsonArray.get(i);
      if (value instanceof JSONObject) {
        array.pushMap(convertJsonToMap((JSONObject) value));
      } else if (value instanceof  JSONArray) {
        array.pushArray(convertJsonToArray((JSONArray) value));
      } else if (value instanceof  Boolean) {
        array.pushBoolean((Boolean) value);
      } else if (value instanceof  Integer) {
        array.pushInt((Integer) value);
      } else if (value instanceof  Double) {
        array.pushDouble((Double) value);
      } else if (value instanceof String)  {
        array.pushString((String) value);
      } else {
        array.pushString(value.toString());
      }
    }
    return array;
  }
}
