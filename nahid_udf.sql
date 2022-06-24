/*
 * Nahid Hasan
 * mysql UDF
 * 25 Jun, 2022
 */
 
DROP FUNCTION IF EXISTS nahid_udf;

CREATE FUNCTION nahid_udf RETURNS string SONAME 'nahid_udf.so';