; Auto-generated. Do not edit!


(cl:in-package package-srv)


;//! \htmlinclude addint-request.msg.html

(cl:defclass <addint-request> (roslisp-msg-protocol:ros-message)
  ((a
    :reader a
    :initarg :a
    :type cl:integer
    :initform 0)
   (b
    :reader b
    :initarg :b
    :type cl:integer
    :initform 0))
)

(cl:defclass addint-request (<addint-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <addint-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'addint-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name package-srv:<addint-request> is deprecated: use package-srv:addint-request instead.")))

(cl:ensure-generic-function 'a-val :lambda-list '(m))
(cl:defmethod a-val ((m <addint-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader package-srv:a-val is deprecated.  Use package-srv:a instead.")
  (a m))

(cl:ensure-generic-function 'b-val :lambda-list '(m))
(cl:defmethod b-val ((m <addint-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader package-srv:b-val is deprecated.  Use package-srv:b instead.")
  (b m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <addint-request>) ostream)
  "Serializes a message object of type '<addint-request>"
  (cl:let* ((signed (cl:slot-value msg 'a)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'b)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <addint-request>) istream)
  "Deserializes a message object of type '<addint-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'a) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'b) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<addint-request>)))
  "Returns string type for a service object of type '<addint-request>"
  "package/addintRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'addint-request)))
  "Returns string type for a service object of type 'addint-request"
  "package/addintRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<addint-request>)))
  "Returns md5sum for a message object of type '<addint-request>"
  "f0b6d69ea10b0cf210cb349d58d59e8f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'addint-request)))
  "Returns md5sum for a message object of type 'addint-request"
  "f0b6d69ea10b0cf210cb349d58d59e8f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<addint-request>)))
  "Returns full string definition for message of type '<addint-request>"
  (cl:format cl:nil "int32 a~%int32 b~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'addint-request)))
  "Returns full string definition for message of type 'addint-request"
  (cl:format cl:nil "int32 a~%int32 b~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <addint-request>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <addint-request>))
  "Converts a ROS message object to a list"
  (cl:list 'addint-request
    (cl:cons ':a (a msg))
    (cl:cons ':b (b msg))
))
;//! \htmlinclude addint-response.msg.html

(cl:defclass <addint-response> (roslisp-msg-protocol:ros-message)
  ((sum
    :reader sum
    :initarg :sum
    :type cl:integer
    :initform 0))
)

(cl:defclass addint-response (<addint-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <addint-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'addint-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name package-srv:<addint-response> is deprecated: use package-srv:addint-response instead.")))

(cl:ensure-generic-function 'sum-val :lambda-list '(m))
(cl:defmethod sum-val ((m <addint-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader package-srv:sum-val is deprecated.  Use package-srv:sum instead.")
  (sum m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <addint-response>) ostream)
  "Serializes a message object of type '<addint-response>"
  (cl:let* ((signed (cl:slot-value msg 'sum)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <addint-response>) istream)
  "Deserializes a message object of type '<addint-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sum) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<addint-response>)))
  "Returns string type for a service object of type '<addint-response>"
  "package/addintResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'addint-response)))
  "Returns string type for a service object of type 'addint-response"
  "package/addintResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<addint-response>)))
  "Returns md5sum for a message object of type '<addint-response>"
  "f0b6d69ea10b0cf210cb349d58d59e8f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'addint-response)))
  "Returns md5sum for a message object of type 'addint-response"
  "f0b6d69ea10b0cf210cb349d58d59e8f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<addint-response>)))
  "Returns full string definition for message of type '<addint-response>"
  (cl:format cl:nil "int32 sum~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'addint-response)))
  "Returns full string definition for message of type 'addint-response"
  (cl:format cl:nil "int32 sum~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <addint-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <addint-response>))
  "Converts a ROS message object to a list"
  (cl:list 'addint-response
    (cl:cons ':sum (sum msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'addint)))
  'addint-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'addint)))
  'addint-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'addint)))
  "Returns string type for a service object of type '<addint>"
  "package/addint")