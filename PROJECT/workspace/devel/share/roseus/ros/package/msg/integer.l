;; Auto-generated. Do not edit!


(when (boundp 'package::integer)
  (if (not (find-package "PACKAGE"))
    (make-package "PACKAGE"))
  (shadow 'integer (find-package "PACKAGE")))
(unless (find-package "PACKAGE::INTEGER")
  (make-package "PACKAGE::INTEGER"))

(in-package "ROS")
;;//! \htmlinclude integer.msg.html


(defclass package::integer
  :super ros::object
  :slots (_sum ))

(defmethod package::integer
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

(setf (get package::integer :md5sum-) "0ba699c25c9418c0366f3595c0c8e8ec")
(setf (get package::integer :datatype-) "package/integer")
(setf (get package::integer :definition-)
      "int32 sum
")



(provide :package/integer "0ba699c25c9418c0366f3595c0c8e8ec")


