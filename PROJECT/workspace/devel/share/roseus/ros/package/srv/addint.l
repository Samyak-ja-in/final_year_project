;; Auto-generated. Do not edit!


(when (boundp 'package::addint)
  (if (not (find-package "PACKAGE"))
    (make-package "PACKAGE"))
  (shadow 'addint (find-package "PACKAGE")))
(unless (find-package "PACKAGE::ADDINT")
  (make-package "PACKAGE::ADDINT"))
(unless (find-package "PACKAGE::ADDINTREQUEST")
  (make-package "PACKAGE::ADDINTREQUEST"))
(unless (find-package "PACKAGE::ADDINTRESPONSE")
  (make-package "PACKAGE::ADDINTRESPONSE"))

(in-package "ROS")





(defclass package::addintRequest
  :super ros::object
  :slots (_a _b ))

(defmethod package::addintRequest
  (:init
   (&key
    ((:a __a) 0)
    ((:b __b) 0)
    )
   (send-super :init)
   (setq _a (round __a))
   (setq _b (round __b))
   self)
  (:a
   (&optional __a)
   (if __a (setq _a __a)) _a)
  (:b
   (&optional __b)
   (if __b (setq _b __b)) _b)
  (:serialization-length
   ()
   (+
    ;; int32 _a
    4
    ;; int32 _b
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _a
       (write-long _a s)
     ;; int32 _b
       (write-long _b s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _a
     (setq _a (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _b
     (setq _b (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass package::addintResponse
  :super ros::object
  :slots (_sum ))

(defmethod package::addintResponse
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass package::addint
  :super ros::object
  :slots ())

(setf (get package::addint :md5sum-) "f0b6d69ea10b0cf210cb349d58d59e8f")
(setf (get package::addint :datatype-) "package/addint")
(setf (get package::addint :request) package::addintRequest)
(setf (get package::addint :response) package::addintResponse)

(defmethod package::addintRequest
  (:response () (instance package::addintResponse :init)))

(setf (get package::addintRequest :md5sum-) "f0b6d69ea10b0cf210cb349d58d59e8f")
(setf (get package::addintRequest :datatype-) "package/addintRequest")
(setf (get package::addintRequest :definition-)
      "int32 a
int32 b
---
int32 sum

")

(setf (get package::addintResponse :md5sum-) "f0b6d69ea10b0cf210cb349d58d59e8f")
(setf (get package::addintResponse :datatype-) "package/addintResponse")
(setf (get package::addintResponse :definition-)
      "int32 a
int32 b
---
int32 sum

")



(provide :package/addint "f0b6d69ea10b0cf210cb349d58d59e8f")


